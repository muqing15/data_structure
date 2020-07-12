package list

import (
	"errors"
)

type ElemType int

type Node struct {
	Data ElemType
	Next *Node
}

type LinkList struct {
	HeadNode *Node
	Len      int
}

func InitLinkList() *LinkList {
	return &LinkList{
		HeadNode: &Node{
			Data: 0,
			Next: nil,
		},
		Len: 0,
	}
}

func ListInsert(l *LinkList, k int, elem *Node) error {
	var node *Node
	if k < 1 || k > l.Len+1 {
		return errors.New("插入位置不正确")
	}

	if k == 1 {
		elem.Next = l.HeadNode.Next
		l.HeadNode.Next = elem
	} else {
		for i := 0; i < k; i++ {
			node = l.HeadNode.Next
		}
		elem.Next = node.Next
		node.Next = elem
	}

	l.Len += 1
	return nil
}
