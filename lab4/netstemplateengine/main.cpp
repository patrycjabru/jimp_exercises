//
// Created by patrycja on 22.03.17.
//
#include <SimpleTemplateEngine.h>
int main() {
    std::string test;

    nets::View view1("Hello {{name}}! How are you today? My name is {{program}}!");
    test=view1.Render({{"name", "Zbigniew"}, {"program", "Borg"}});
    std::cout << "\ninput: " << "Hello {{name}}! How are you today? My name is {{program}}!";
    std::cout << "\noutput: " << test << "\n";

    nets::View view2("Person:\n\tName: {{name}}\n\tSurname: {{surname}}\n\tAge: {{age}}\n");
    test=view2.Render({{"name", "Jan"}, {"surname", "Kowalski"}, {"age", "33"}});
    std::cout << "\ninput: " << "Person:\n\tName: {{name}}\n\tSurname: {{surname}}\n\tAge: {{age}}\n";
    std::cout << "\noutput: " << test << "\n";

    nets::View view3("Test {{test}}");
    test=view3.Render({{"test", "56$"}});
    std::cout << "\ninput: " << "Test {{test}}";
    std::cout << "\noutput: " << test << "\n";

    nets::View view4("Test {{test}}");
    test=view4.Render({{"test", "%%"}});
    std::cout << "\ninput: " << "Test {{test}}";
    std::cout << "\noutput: " << test << "\n";

    nets::View view5("test {{test}} of {test} but {{test} or {test}} and {{{test}}}");
    test=view5.Render({{"test", "888"}});
    std::cout << "\ninput: " << "test {{test}} of {test} but {{test} or {test}} and {{{test}}}";
    std::cout << "\noutput: " << test << "\n";

    nets::View view6("Test {{test}} missing:{{missing}}:missing");
    test=view6.Render({{"test", "replacement"}});
    std::cout << "\ninput: " << "Test {{test}} missing:{{missing}}:missing";
    std::cout << "\noutput: " << test << "\n";

    nets::View view7("{{template_with_underscore}}<=>{{template_with_undersocre_missing}}");
    test=view7.Render({{"template_with_underscore", "replacement"}});
    std::cout << "\ninput: " << "{{template_with_underscore}}<=>{{template_with_undersocre_missing}}";
    std::cout << "\noutput: " << test << "\n";

    nets::View view8("{{t09}}<=>{{t17}}");
    test=view8.Render({{"t17", "Am I?"}});
    std::cout << "\ninput: " << "\"{{t09}}<=>{{t17}}\"";
    std::cout << "\noutput: " << test << "\n";
    return 0;
}