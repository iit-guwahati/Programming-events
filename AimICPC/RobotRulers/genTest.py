import random
import operator

MAX = 1000000000

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
	return (len(locs), locs)

	return True

def intersect(a, b):
	if a[0]>=b[0] and a[1]<=b[1]:
		return a
	elif a[0]<=b[0] and a[1]>=b[1]:
		return b
	elif a[0]<=b[0] and a[1]>=b[0]:
		return (b[0], a[1])
	elif a[0]>=b[0] and a[0]<=b[1]:
		return (a[0], b[1])
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
		if poss==(-1,-1):
			break
		if debug==1:
			print poss
	if poss==(-1,-1):
		return (-1, -1)
	else:
		return (poss[0], poss[1])

def genTestCases(T):
	inp = open('input','w')
	ans = open('output','w')
	inp.write(str(T)+"\n")
	for i in xrange(0,T):
		N = random.randint(1,100000)
		(N,locs) = gen(N)
		inp.write(str(N)+"\n")
		if random.random()<0.015:
			locs[random.randint(0,N-1)]=locs[random.randint(0,N-1)]
		inp.write(str(locs[0]))
		for j in locs[1:]:
			inp.write(" "+str(j))
		inp.write("\n")
		answer = solve(locs)
		if answer==(-1,-1):
			ans.write("-1\n")
		else:
			ans.write(str(answer[0])+" "+str(answer[1])+"\n")
	inp.close()
	ans.close()

genTestCases(100)

#Functions for testing the correctness of the solution
def test(locs, answer):
	if not answer==(-1, -1):
		if checkx(locs, answer[0]) and checkx(locs, answer[1]) and (answer[0]==0 or not checkx(locs, answer[0]-1)) and (answer[1]==MAX or not checkx(locs, answer[1]+1)):
			print "YES!"
		else:
			print "NO"
			a = open('error','a')
			a.write(reduce(lambda x, y: x+" "+y, map(str,locs))+"\n")
			a.close()

def checkx(locs, answer):
	dist = map(lambda y: abs(answer-y), locs)
	for i in xrange(0, len(dist)-1):
		if dist[i]>dist[i+1]:
			return False
	return True
