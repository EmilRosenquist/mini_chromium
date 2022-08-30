#include <string>
#include <base/files/file_path.h>

#undef NDEBUG
#include <cassert>

int main()
{
    {
        const auto filepath = base::FilePath("path/to/file");
#if BUILDFLAG(IS_POSIX)
        assert(std::string("file") == filepath.BaseName().value());
#elif BUILDFLAG(IS_WIN)
        assert(std::wstring("file") == filepath.BaseName().value());
#endif        
    }
}