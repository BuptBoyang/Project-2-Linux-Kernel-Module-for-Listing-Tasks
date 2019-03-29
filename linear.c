#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/sched/task.h>
#include <linux/sched/signal.h>

int tasks_lister(void)
{
  struct task_struct *task;  
  printk(KERN_INFO "List tasks linearly.\n"); 
  for_each_process(task)
  {
    printk(KERN_INFO "pid: %d | pname: %s | state: %ld\n", task->pid, task->comm, task->state);
  }
  return 0;
}

void tasks_lister(void)
{
  printk(KERN_INFO "Module removed.\n");
}

module_init(tasks_lister);
module_exit(tasks_lister);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Iterating over Tasks Linearly");
MODULE_AUTHOR("zby");
