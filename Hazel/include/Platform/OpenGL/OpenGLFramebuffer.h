//
// Created by ZZK on 2023/1/13.
//

#pragma once

#include <Hazel/Renderer/Framebuffer.h>

namespace Hazel
{

    class OpenGLFramebuffer : public Framebuffer
    {
    public:
        OpenGLFramebuffer(const FramebufferSpecification& spec);
        virtual ~OpenGLFramebuffer();

        void Invalidate();

        virtual void Bind() override;
        virtual void Unbind() override;

        virtual void Resize(uint32_t width, uint32_t height) override;

        virtual int ReadPixel(uint32_t attachmentIndex, int x, int y) override;

        virtual void ClearAttachment(uint32_t attachmentIndex, int value) override; // Clear a specific attachment within framebuffer to a particular value

        virtual uint32_t GetColorAttachmentRendererID(uint32_t index = 0) const override
        {
            HZ_CORE_ASSERT(index < m_ColorAttachments.size());
            return m_ColorAttachments[index];
        }

        virtual const FramebufferSpecification& GetSpecification() const override { return m_Specification; }

    private:
        uint32_t m_RendererID = 0;
        FramebufferSpecification m_Specification;

        std::vector<FramebufferTextureSpecification> m_ColorAttachmentSpecifications;
        FramebufferTextureSpecification m_DepthAttachmentSpecification = FramebufferTextureFormat::None;    // TODO: fix me

        std::vector<uint32_t> m_ColorAttachments;
        uint32_t m_DepthAttachment = 0;
    };
}



















