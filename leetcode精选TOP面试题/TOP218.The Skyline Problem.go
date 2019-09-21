package main

type HeightHeap []int

func (h HeightHeap) Len() int { return len(h) }
func (h HeightHeap) Less(i, j int) bool {
	return h[i] > h[j]
}
func (h HeightHeap) Swap(i, j int) { h[i], h[j] = h[j], h[i] }

func (h *HeightHeap) Push(x interface{}) {
	*h = append(*h, x.(int))
}

func (h *HeightHeap) Pop() interface{} {
	n := len(*h)
	x := (*h)[n-1]
	*h = (*h)[0 : n-1]
	return x
}

type Buildings [][]int

func (b Buildings) Len() int      { return len(b) }
func (b Buildings) Swap(i, j int) { b[i], b[j] = b[j], b[i] }
func (b Buildings) Less(i, j int) bool {
	if b[i][0] == b[j][0] {
		return b[i][1] > b[j][1]
	}
	return b[i][0] < b[j][0]
}

func getSkyline(buildings [][]int) [][]int {
	sb := Buildings{} // sb== sortedBuildings😂
	for _, b := range buildings {
		sb = append(sb, []int{b[0], b[2]})
		sb = append(sb, []int{b[1], -b[2]})
	}
	sort.Sort(sb)
	fmt.Println(sb)
	preh := []int{0, 0} // prev heightest point
	curh := 0           // current heightest point
	hs := HeightHeap{}
	skyline := [][]int{}
	for _, b := range sb {
		// 左边入 右边出
		fmt.Println("hs is ", hs)
		if b[1] > 0 {
			heap.Push(&hs, b[1])
		} else {
			index := -1
			for i := 0; i < len(hs); i++ {
				if hs[i] == -b[1] {
					index = i
					break
				}
			}
			if index != -1 {
				heap.Remove(&hs, index)
			}
		}

		if len(hs) > 0 {
			curh = hs[0]
		} else {
			curh = 0
		}
		if preh[1] != curh {
			preh[1] = curh
			preh[0] = b[0]
			skyline = append(skyline, []int{b[0], curh})
		}
	}
	return skyline
}
