#pragma once

#include "../Core/Base.h"

namespace High::OpenGL {

    enum class ImageFormat {
        None = 0,
        R8,
        RGB8,
        RGBA8,
        RGBA32F
    };

    struct TextureSpecification {
        uint32_t Width = 1;
        uint32_t Height = 1;
        ImageFormat Format = ImageFormat::RGBA8;
        bool GenerateMps = true;
    };

    class Texture {
    public:
        Texture() = default;
        ~Texture() = default;
        TextureSpecification& GetSpecification();

        uint32_t GetWidth();
        uint32_t GetHeight();
        uint32_t GetRendererID();

        const std::string& GetPath() const;
        void Bind(uint32_t slot = 0);
        bool IsLoaded();

        bool operator ==(const Texture& other);
    };

    class Texture2D: public Texture {
    public:
        explicit Texture2D(const TextureSpecification &specification);

        static Texture2D* Create(const TextureSpecification& specification);
        static Texture2D* Create(const std::string& path);

    private:
        std::string m_Path;
        bool m_IsLoaded = false;
        uint32_t m_Width{}, m_Height{};
        uint32_t m_RendererID{};
        GLenum m_InternalFormat{}, m_DataFormat{};
    };

}