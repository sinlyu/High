#pragma once
#include "../Core/Base.h"

namespace High::OpenGL {
    enum class ShaderDataType {
        None = 0,
        Float, Float2, Float3, Float4,
        Mat3, Mat4,
        Int, Int2, Int3, Int4,
        Bool
    };

    static uint32_t ShaderDataTypeSize(ShaderDataType type)
    {
        switch (type)
        {
            case ShaderDataType::Float: return 4;
            case ShaderDataType::Float2: return 4 * 2;
            case ShaderDataType::Float3: return 4 * 3;
            case ShaderDataType::Float4: return 4 * 4;
            case ShaderDataType::Mat3: return 4 * 3 * 3;
            case ShaderDataType::Mat4: return 4 * 4 * 4;
            case ShaderDataType::Int: return 4;
            case ShaderDataType::Int2: return 4 * 2;
            case ShaderDataType::Int3: return 4 * 3;
            case ShaderDataType::Int4: return 4 * 4;
            case ShaderDataType::Bool: return 1;
            default: break;
        }

        VERIFY(false);
        return 0;
    }

    struct BufferElement {
        std::string Name;
        ShaderDataType Type;
        uint32_t Size{};
        uint32_t Offset{};
        bool Normalized{};

        BufferElement() = default;

        BufferElement(const ShaderDataType type, std::string name, const bool normalized = false)
                : Name(std::move(name)), Type(type), Size(ShaderDataTypeSize(type)), Offset(0), Normalized(normalized)
        {}

        [[nodiscard]] uint32_t GetComponentCount() const {
            switch (Type) {
                case ShaderDataType::Float: return 1;
                case ShaderDataType::Float2: return 2;
                case ShaderDataType::Float3: return 3;
                case ShaderDataType::Float4: return 4;
                case ShaderDataType::Mat3: return 3 * 3;
                case ShaderDataType::Mat4: return 4 * 4;
                case ShaderDataType::Int: return 1;
                case ShaderDataType::Int2: return 2;
                case ShaderDataType::Int3: return 3;
                case ShaderDataType::Int4: return 4;
                case ShaderDataType::Bool: return 1;
                default: break;
            }

            VERIFY(false);
            return 0;
        }
    };

    class BufferLayout {
    public:
        BufferLayout() = default;

        BufferLayout(std::initializer_list<BufferElement> elements)
                : m_Elements(elements) {
            CalculateOffsetsAndStride();
        }

        [[nodiscard]] uint32_t GetStride() const { return m_Stride; }
        [[nodiscard]] const std::vector<BufferElement>& GetElements() const { return m_Elements; }

        [[nodiscard]] std::vector<BufferElement>::iterator begin() { return m_Elements.begin(); }
        [[nodiscard]] std::vector<BufferElement>::iterator end() { return m_Elements.end(); }
        [[nodiscard]] std::vector<BufferElement>::const_iterator begin() const { return m_Elements.begin(); }
        [[nodiscard]] std::vector<BufferElement>::const_iterator end() const { return m_Elements.end(); }
    private:
        void CalculateOffsetsAndStride() {
            size_t offset = 0;
            m_Stride = 0;
            for (auto& element : m_Elements) {
                element.Offset = offset;
                offset += element.Size;
                m_Stride += element.Size;
            }
        }

        std::vector<BufferElement> m_Elements;
        uint32_t m_Stride = 0;
    };

    class VertexBuffer {
    public:
        explicit VertexBuffer(uint32_t size);
        ~VertexBuffer();

        void Bind() const;
        BufferLayout& GetLayout();
        void SetLayout(const BufferLayout& layout);

        static void Unbind();

        void SetData(const void* data, uint32_t size) const;

    private:
        uint32_t m_RendererID{};
        BufferLayout m_Layout;
    };
}
