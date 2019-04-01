#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/sched/task.h>
#include <linux/sched/signal.h>

int linear_init(void)
{
  struct task_struct *task;  
  for_each_process(task)
  {
    printk(KERN_INFO "pid: %d\tpname: %s\tstate: %ld\n", task->pid, task->comm, task->state);
  }
  return 0;
}

void linear_exit(void)
{
  printk(KERN_INFO "Module removed.\n");
}

module_init(linear_init);
module_exit(linear_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Iterating over Tasks Linearly");
MODULE_AUTHOR("zby");
