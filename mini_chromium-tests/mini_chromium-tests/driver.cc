#include <string>

#include <mini_chromium/base/files/file_path.h>

#undef NDEBUG
#include <cassert>

int main()
{
    {
#if BUILDFLAG(IS_POSIX)
        const auto filepath = base::FilePath("path/to/file");
        assert(std::string("file") == filepath.BaseName().value());
#elif BUILDFLAG(IS_WIN)
        const auto filepath = base::FilePath(L"path/to/file");
        assert(std::wstring(L"file") == filepath.BaseName().value());
#endif
    }
}
