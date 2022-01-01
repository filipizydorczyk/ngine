namespace NGine
{
    struct LayoutElement
    {
        // std::string Name;
        // ShaderDataType Type;
        uint32_t size;
        size_t offset;
        bool normalized;
    };

    class VertexLayouts
    {
    private:
        std::vector<LayoutElement> m_Elements;
        uint32_t m_Stride = 0;
    };
};