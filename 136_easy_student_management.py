def twodigit(n):
    return '{0:.2f}'.format(n)

# split the first input to get the range of int
numOfStudents,numOfAssignments = (int(n) for n in raw_input().split())
avgs = []
print "\n"

for _ in range(numOfStudents):
	line = raw_input().strip()
	name = line.split()[0]
	grades = line.split()[1:]
	grades = (float(grade) for grade in grades)
	# calc the avgs
	avgs.append((name, sum(grades)/numOfAssignments))

print twodigit(sum(x[1] for x in avgs)/numOfStudents)
for stud, avg in avgs:
    print "%s %s" % (stud, twodigit(avg))

