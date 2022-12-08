
#include <iostream>
#include "cppmain.h"

extern "C" {

    int main(int argc, const char *argv[]) {
        std::string cmd{};
        std::vector<std::string> args{};
        if (argc < 1) {
            std::cerr << "Unexpected invocation context: argc<1\n";
            return 1;
        }
        cmd.append(argv[0]);
        args.reserve(argc - 1);
        for (typeof(argc) i = 1; i < argc; i++) {
            std::string &arg = args.emplace_back();
            arg.append(argv[i]);
        }
        return cppmain(cmd, args);
    }

}