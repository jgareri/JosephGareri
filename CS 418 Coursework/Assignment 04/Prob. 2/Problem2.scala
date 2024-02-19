//Problem1.scala
//Joseph Gareri
//00099183
//jgareri@my.athens.edu
//Asg 04 | Prob. 2
//Used Assignment 3 as reference


case class Node(value: Int, next: Option[Node])

def insertNode(node: Node, lst: Option[Node]): Option[Node] = lst match {
    case None => Some(node)
    case Some(head) if node.value < head.value => Some(Node(node.value, lst))
    case Some(head) => Some(Node(head.value, insertNode(node, head.next)))
}

case class BinaryTree(value: Int, left: Option[BinaryTree], right: Option[BinaryTree])

def insertTree(tree: Option[BinaryTree], atom: Int): Option[BinaryTree] = tree match {
    case None => Some(BinaryTree(atom, None, None))
    case Some(node) if atom < node.value => Some(BinaryTree(node.value, insertTree(node.left, atom), node.right))
    case Some(node) => Some(BinaryTree(node.value, node.left, insertTree(node.right, atom)))
}

def deleteTree(tree: Option[BinaryTree], atom: Int): Option[BinaryTree] = tree match {
    case None => None
    case Some(node) if atom == node.value => node.right
    case Some(node) => Some(BinaryTree(node.value, deleteTree(node.left, atom), node.right))
}

def checkTreeEmpty(tree: Option[BinaryTree]): Boolean = tree.isEmpty

def member(tree: Option[BinaryTree], atom: Int): Boolean = tree match {
    case None => false
    case Some(node) if atom == node.value => true
    case Some(node) => member(node.left, atom) || member(node.right, atom)
}

def inOrder(tree: Option[BinaryTree]): List[Int] = tree match {
    case None => Nil
    case Some(node) => inOrder(node.left) ::: List(node.value) ::: inOrder(node.right)
}

def preOrder(tree: Option[BinaryTree]): List[Int] = tree match {
    case None => Nil
    case Some(node) => node.value :: preOrder(node.left) ::: preOrder(node.right)
}

def postOrder(tree: Option[BinaryTree]): List[Int] = tree match {
    case None => Nil
    case Some(node) => postOrder(node.left) ::: postOrder(node.right) ::: List(node.value)
}

object Main {
    def main(args: Array[String]): Unit = {
        val node = Node(1, None)
        val list = Some(Node(2, None))
    
        val insertedNode = insertNode(node, list)
        println(s"Inserting $node into $list results in $insertedNode")

        val tree = Some(BinaryTree(2, Some(BinaryTree(1, None, None)), Some(BinaryTree(3, None, None))))
        val atom = 5

        val insertedTree = insertTree(tree, atom)
        println(s"Inserting $atom into $tree results in $insertedTree")

        val deletedTree = deleteTree(tree,1)
        println(s"Deleting 1 from $tree results in $deletedTree")

        val isEmpty = checkTreeEmpty(tree)
        println(s"Checking if tree is empty results in: $isEmpty")

        val isMember = member(tree,2)
        println(s"Checking if 2 is a member of tree results in: $isMember")

        val orderedTree = inOrder(tree)
        println(s"In-order traversal of tree results in: $orderedTree")

        val preOrderedTree = preOrder(tree)
        println(s"Pre-order traversal of tree results in: $preOrderedTree")

        val postOrderedTree = postOrder(tree)
        println(s"Post-order traversal of tree results in: $postOrderedTree")

    }
}