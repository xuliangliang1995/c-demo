//
// Created by 许良 on 2021/2/14.
//
#include <generic_ext.h>

int main() {
    typedef struct Person {
        char *id;
        int age;
        char *name;
    } Person;

    Person person = {.id="1", .age=18, .name="jerry"};

    Printlnf("Person{id=%s, age=%d, name=%s}", person.id, person.age, person.name);

    // 通过指针获取姓名
    Person *p_person = &person;
    Printlnf("%s", p_person -> name);
    return 0;
}
