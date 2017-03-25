//
// Created by patrycja on 22.03.17.
//
#include <SimpleTemplateEngine.h>
int main() {
    nets::View view1("Hello {{name}}! How are you today? My name is {{program}}!");
    std::string aaa=view1.Render({{"name", "Zbigniew"}, {"program", "Borg"}});
    std::cout << "output:\n" << aaa;
    return 0;
}