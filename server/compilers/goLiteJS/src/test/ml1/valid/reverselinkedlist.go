package main

type node struct {
  val string;
  next int;
}

func main() {
  var (
    nodes []node
    head = 0
  )

  nodes = append(nodes, initNode("node0", 1))
  nodes = append(nodes, initNode("node1", 2))
  nodes = append(nodes, initNode("node2", -1))

  head = reverseLinkedList(head, nodes)

  for (head != -1) {
    println(nodes[head].val)
    head = nodes[head].next
  }
}

func initNode(val string, next int) node {
  var newNode node
  newNode.val = val
  newNode.next = next

  return newNode
}

func reverseLinkedList(head int, nodes []node) int {
  /*
    reverses the linked list and returns the index of the new head
   */
  
  prevNode := -1
  curNode := head

  for curNode != -1 {
    curNodeVal := nodes[curNode]

    nextNode := curNodeVal.next
    curNodeVal.next = prevNode
    nodes[curNode] = curNodeVal

    prevNode = curNode
    curNode = nextNode
  }

  return prevNode
}
