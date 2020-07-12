package list

import (
	. "data_structure/src/common"
	"fmt"
	"testing"
)

func TestInitLinkList(t *testing.T) {
	l := InitLinkList()
	err := ListInsert(l, 1, &Node{Data: 4})
	CheckErr(err)
	err = ListInsert(l, 2, &Node{Data: 3})
	CheckErr(err)
	err = ListInsert(l, 1, &Node{Data: 1})
	CheckErr(err)
	err = ListInsert(l, 2, &Node{Data: 2})
	CheckErr(err)
	err = ListInsert(l, 6, &Node{Data: 2})
	CheckErr(err)
	for node := l.HeadNode; node != nil; node = node.Next {
		fmt.Println(node.Data)
	}
}
