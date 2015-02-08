class BusinessTasks:
    def getTask(self, tasks, n):
        tasks = list(tasks)
        pos = 0
        while len(tasks) > 1:
            remove = (pos+n-1) % len(tasks)
            del tasks[remove]
            pos = remove % len(tasks)

        return tasks[0]

bt = BusinessTasks()
print bt.getTask(("a", "b", "c", "d"), 2)



# vim: expandtab softtabstop=4 tabstop=4 shiftwidth=4 ts=4 sw=4

