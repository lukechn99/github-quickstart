```
,---------------------.,---------------------.,---------------------.
|         VM          ||         VM          ||         VM          |
|         01          ||         02          ||         03          |
|     [CPU] [RAM]     ||     [CPU] [RAM]     ||     [CPU] [RAM]     |
|      [Storage]      ||      [Storage]      ||      [Storage]      |
| [Network Interface] || [Network Interface] || [Network Interface] |
`---------------------'`---------------------'`---------------------'
,-------------------------------------------------------------------.
|                            Hypervisor                             |
`-------------------------------------------------------------------'
,-------------------------------------------------------------------.
|                             Hardware                              |
`-------------------------------------------------------------------'
```
The hypervisor layer helps partition/allocate hardware resources to one or more VMs on a machine. 
