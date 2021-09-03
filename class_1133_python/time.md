# 9/5/18 Time 

“Time” is a module that is not a natural part of Python, to use “time” and different functions of time, it must be imported with the following line of code:

```import time```

Other modules similar to “time” include “datetime” and “calendar”

```
Python 3.7.0 (v3.7.0:1bf9cc5093, Jun 27 2018, 04:06:47) [MSC v.1914 32 bit (Intel)] on win32
Type "help", "copyright", "credits" or "license" for more information.
>>> import time
>>> def leap(year):
...     if year%400:
...             return "true"
...
...
```

## Math with time
```
>>> def leap(year):
...     if year%400==0:
...             return "true"
...     elif year%100==0:
...             return "false"
...     elif year%4==0:
...             return "true"
...     else:
...             return "false"
...
>>> print(leap(2018))
false
>>> print(leap(time.time()//(60*60*24*365)))
true
>>> print(leap(time.time()//(60*60*24*365)+1970))
false
>>> time.time()
1536202229.4774811
```

## Travel back in time
```
Python 3.8.3 (tags/v3.8.3:6f8c832, May 13 2020, 22:20:19) [MSC v.1925 32 bit (Intel)] on win32
Type "help", "copyright", "credits" or "license" for more information.
>>> from datetime import datetime, timedelta
>>> time = datetime.now()
>>> date_one_week_ago = (time - timedelta(days=7)).strftime('%Y-%m-%d')
>>> date_now = time.strftime('%Y-%m-%d')
>>> print("a week ago, it was " + date_one_week_ago + ", but now it is " + date_now)
a week ago, it was 2020-07-25, but now it is 2020-08-01
>>> 
