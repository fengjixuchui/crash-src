#include<linux/init.h>
#include<linux/slab.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/list.h>

struct student
{
    int id;
    char *name;
    struct list_head list;
};

void print_student(struct student *);

static int linklist_init(void)
{
    struct student *stu1, *stu2, *stu3, *stu4;
    struct student *stu;
    struct student *stu_panic_trigger;

    // init a list head
    LIST_HEAD(stu_head);
    // init four list nodes
    stu1 = kmalloc(sizeof(*stu1), GFP_KERNEL);
    stu1->id = 1;
    stu1->name = "fanfan1";
    INIT_LIST_HEAD(&stu1->list);

    stu2 = kmalloc(sizeof(*stu2), GFP_KERNEL);
    stu2->id = 2;
    stu2->name = "fanfan2";
    INIT_LIST_HEAD(&stu2->list);

    stu3 = kmalloc(sizeof(*stu3), GFP_KERNEL);
    stu3->id = 3;
    stu3->name = "fanfan3";

    INIT_LIST_HEAD(&stu3->list);
    stu4 = kmalloc(sizeof(*stu4), GFP_KERNEL);
    stu4->id = 4;
    stu4->name = "fanfan4";
    INIT_LIST_HEAD(&stu4->list);

    list_add (&stu1->list, &stu_head);
    list_add (&stu2->list, &stu_head);
    list_add (&stu3->list, &stu_head);
    list_add (&stu4->list, &stu_head);

    list_for_each_entry(stu, &stu_head, list)
    {
        print_student(stu);
    }

    // print each student from 1 to 4
    list_for_each_entry_reverse(stu, &stu_head, list)
    {
        print_student(stu);
    }

    // delete a entry stu2
    list_del(&stu2->list);

    printk(KERN_INFO "prev: %lx %p\n", (long int)(stu2->list.prev), stu2->list.prev);
    printk(KERN_INFO "next: %lx %p\n", (long int)(stu2->list.next), stu2->list.next);
    stu_panic_trigger = container_of(stu2->list.prev, struct student, list);
    stu_panic_trigger->name = "hacker";

    list_for_each_entry(stu, &stu_head, list)
    {
        print_student(stu);
    }

    // replace stu3 with stu2
    list_replace(&stu3->list, &stu2->list);
    list_for_each_entry(stu, &stu_head, list)
    {
        print_student(stu);
    }
    return 0;
}

void print_student(struct student *stu)
{
    printk (KERN_ALERT "======================\n");
    printk (KERN_ALERT "id  =%d\n", stu->id);
    printk (KERN_ALERT "name=%s\n", stu->name);
    printk (KERN_ALERT "======================\n");
}

static void linklist_exit(void)
{
    printk(KERN_ALERT "*************************\n");
    printk(KERN_ALERT "linklist is exited!\n");
    printk(KERN_ALERT "*************************\n");
}


module_init(linklist_init);
module_exit(linklist_exit);
MODULE_LICENSE("GPL");
