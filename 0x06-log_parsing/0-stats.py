#!/usr/bin/python3
"""
log parsing
script that reads stdin line by line and computes metrics
"""
status = {"200": 0, "301": 0,
          "400": 0, "401": 0,
          "403": 0, "404": 0,
          "405": 0, "500": 0}
count = 0
length = 0
log = ""
try:
    import sys
    for log in sys.stdin:
        count += 1
        word = log.split(" ")
        if len(word) >= 1:
            length += int(word[-1])
            if word[-2] in status:
                status[word[-2]] += 1

        if count == 10:
            print("File size:", length)
            for key in status.keys():
                if status[key] != 0:
                    print("%s: %d" % (key, status[key]))
except:
    continue
else:
    print("file size:", length)
    for key in status.keys():
        if status[key] != 0:
            print("%s: %d" % (key, status[key]))
