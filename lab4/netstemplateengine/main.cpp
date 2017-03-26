//
// Created by patrycja on 22.03.17.
//
#include <SimpleTemplateEngine.h>
int main() {
    nets::View view1("{{template_with_underscore}}<=>{{template_with_undersocre_missing}}");
    std::string aaa=view1.Render({{"template_with_underscore", "replacement"}});
    std::cout << "\noutput:\n" << aaa;
    return 0;
}