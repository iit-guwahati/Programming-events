import random
import operator

MAX = 1000000000

def doOnce():
	start = random.randint(0,1000000000)
	distance = 0
	locs = []
	while 1:
		distance = random.randint(distance+1, min(start, 1000000000-start))
		if abs(distance-min(start, 1000000000-start))<100:
			break
		locs += [start+distance*(random.randint(0,1)*2-1)]
	print locs, len(locs)


def gen(N):
	MAX = 1000000000
	#Generate N random numbers
	#Generate random start
	#Map the distances, sort, output in order
	locs = [random.randint(0, MAX) for i in xrange(0,N)]
	start = random.randint(0, MAX)
	locs_map = {abs(i-start):i for i in locs}
	locs_sorted = sorted(locs_map.iteritems(), key=operator.itemgetter(0))
	locs = [i[1] for i in locs_sorted]
	print reduce(lambda x, y: x+" "+y, map(str,locs))
	print start
	answer = solve(locs)
	if answer==(-1, -1):
		print -1
	else:
		print answer[0], answer[1]
	if check(locs, answer[0]) and check(locs, answer[1]) and (answer[0]==0 or not check(locs, answer[0]-1)) and (answer[1]==MAX or not check(locs, answer[1]+1)):
		print "YES!"
	else:
		print "NO"

def check(locs, answer):
	dist = map(lambda y: abs(answer-y), locs)
	for i in xrange(0, len(dist)-1):
		if dist[i]>dist[i+1]:
			return False
	return True

def intersect(a, b):
	if a[0]>=b[0] and a[1]<=b[1]:
		return a
	elif a[0]<=b[0] and a[1]>=b[1]:
		return b
	elif a[0]<b[0] and a[1]>b[0]:
		return (b[0], a[1])
	elif a[0]>b[0] and a[0]<b[1]:
		return (a[0], b[1])
	print "Empty intersection! ", a, b
	return (-1,-1)

def solve(locs, debug=0):
	MAX = 1000000000
	left = right = locs[0]
	poss = (0, MAX)
	for i in xrange(1, len(locs)):
		if locs[i]<=left:
			poss = intersect(poss, ((locs[i]+right)/2 + (locs[i]+right)%2, MAX))
			left = locs[i]
		elif locs[i]>=right:
			poss = intersect(poss, (0, (locs[i]+left)/2))
			right = locs[i]
		else:
			poss = (-1,-1)
			break
		if debug==1:
			print poss
	if poss==(-1,-1):
		return (-1, -1)
	else:
		return (poss[0], poss[1])

gen(100)
