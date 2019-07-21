
type LRUCache struct {
	cache    map[int]*list
	head     *list
	tail     *list
	size     int
	capacity int
}

type list struct {
	next *list
	pre  *list
	key  int
	val  int
}

func Constructor(capacity int) LRUCache {
	head := &list{}
	tail := &list{}
	tail.pre = head
	head.next = tail
	return LRUCache{make(map[int]*list), head, tail, 0, capacity}
}

func deleteNode(node *list) {
	node.pre.next = node.next
	node.next.pre = node.pre
}

func (this *LRUCache) Add(node *list) {
	node.next = this.head.next
	node.next.pre = node
	node.pre = this.head
	this.head.next = node
}

func (this *LRUCache) Get(key int) int {
	if v, ok := this.cache[key]; ok {
		deleteNode(v)
		this.Add(v)
		return v.val
	}
	return -1
}

func (this *LRUCache) Put(key int, value int) {
	if v, ok := this.cache[key]; ok {
		v.val = value
		deleteNode(v)
		this.Add(v)
	} else {
		new := &list{nil, nil, key, value}
		this.size += 1
		if this.size > this.capacity {
			delete(this.cache, this.tail.pre.key)
			deleteNode(this.tail.pre)
			this.size -= 1
		}
		this.cache[key] = new
		this.Add(new)
	}
}
