
type MinStack struct {
	stack     []int
	min_stack []int
}

/** initialize your data structure here. */
func Constructor() MinStack {
	return MinStack{make([]int, 0), make([]int, 0)}
}

func (this *MinStack) Push(x int) {
	this.stack = append(this.stack, x)
	if len(this.min_stack) == 0 || x <= this.min_stack[len(this.min_stack)-1] {
		this.min_stack = append(this.min_stack, x)
	}
}

func (this *MinStack) Pop() {
	if len(this.stack) == 0 {
		return
	}
	if len(this.min_stack) != 0 && this.stack[len(this.stack)-1] == this.min_stack[len(this.min_stack)-1] {
		this.min_stack = this.min_stack[:len(this.min_stack)-1]
	}
	this.stack = this.stack[:len(this.stack)-1]
}

func (this *MinStack) Top() int {
	return this.stack[len(this.stack)-1]
}

func (this *MinStack) GetMin() int {
	return this.min_stack[len(this.min_stack)-1]
}

