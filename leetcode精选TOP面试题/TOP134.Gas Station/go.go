package main

func canCompleteCircuit(gas []int, cost []int) int {
	start := 0
	cur := 0
	left := 0
	for index, val := range cost {
		left += gas[index] - val
		cur += gas[index] - val
		if cur < 0 {
			start = index + 1
			cur = 0
		}
	}
	if left < 0 {
		return -1
	}
	return start
}
