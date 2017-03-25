//
// Created by patrycja on 22.03.17.
//
#include <SimpleTemplateEngine.h>
int main() {
    nets::View view1("test {{test}} of {test} but {{test} or {test}} and {{{test}}}");
    std::string aaa=view1.Render({{"test", "888"}});
    std::cout << "output:\n" << aaa;
    return 0;
}