from collections import deque
import unittest

class TreeNode:
    def __init__(self, value):
        self.value = value
        self.children = []

class Tree:
    def __init__(self, root=None):
        self.root = root

    def build_tree(self, data):
        """Build a tree from the nested list structure."""
        if not data:
            return None
        root = TreeNode(data[0])
        for child_data in data[1]:
            child_node = self.build_tree(child_data)
            if child_node:
                root.children.append(child_node)
        return root
    
    def level_order_traversal(self, root):
        """Perform level-order traversal and print level and node value."""
        if not root:
            return []

        result = []
        queue = deque([(root, 0)])  # (node, level)

        while queue:
            node, level = queue.popleft()
            result.append((level, node.value))  # Store level and node value

            # Enqueue all children with incremented level
            for child in node.children:
                queue.append((child, level + 1))

        return result

    def removeLevel(self, root, level):
        """Removes nodes at the specified level using level-order traversal."""
        if not root or level < 0:
            return root

        # Store nodes in a queue for level-order traversal
        queue = deque([(root, 0)])  # (node, current_level)
        parents = {root: None}  # Track parents to facilitate child promotion

        # First pass: build parent mapping
        while queue:
            node, current_level = queue.popleft()

            # Only process children if we are not at the level to remove
            for child in node.children:
                parents[child] = node
                queue.append((child, current_level + 1))

        # Second pass: remove nodes at the specified level
        queue.append((root, 0))  # Reset the queue for another pass
        while queue:
            node, current_level = queue.popleft()

            if current_level == level:
                parent = parents[node]
                if parent:  # If the node has a parent
                    parent.children.extend(node.children)  # Promote children
                    parent.children.remove(node)  # Remove the node from its parent's children
                continue  # Skip processing this node's children

            # Process children nodes
            for child in node.children:
                queue.append((child, current_level + 1))

        return root

    def tree_to_list(self, node):
        """Convert the tree back into a nested list structure."""
        if not node:
            return None
        return [node.value, [self.tree_to_list(child) for child in node.children]]

class TestRemoveLevels(unittest.TestCase):
    def setUp(self):
        # Build the tree for the test cases
        #         1
        #       / |  \
        #      2  3   4
        #     /|      |
        #    5 6      7
        #   /|\      / \
        #  8 9 10   11 12

        self.tree = Tree()
        self.root = self.tree.build_tree([
            1, 
            [
                [2, 
                    [
                        [5, [[8, []], [9, []], [10, []]]], 
                        [6, []]
                    ]
                ], 
                [3, []], 
                [4, 
                    [
                        [7, [[11, []], [12, []]]]
                    ]
                ]
            ]
        ])

    def test_remove_level_1(self):
        level = 1  # Remove nodes at level 1 (2, 3, 4)
        print(self.tree.level_order_traversal(self.root), "Level to remove:", level)
        new_root = self.tree.removeLevel(self.root, level)
        result = self.tree.tree_to_list(new_root)
        expected = [1, [
            [5, [[8, []], [9, []], [10, []]]], 
            [6, []], 
            [7, [[11, []], [12, []]]]
        ]]
        print(self.tree.level_order_traversal(new_root), "After removal of Level:", level)
        self.assertEqual(result, expected, "Failed to remove nodes at given level")

    def test_remove_level_2(self):
        level = 2  # Remove nodes at level 2 (5, 6, 7)
        print(self.tree.level_order_traversal(self.root), "Level to remove:", level)
        new_root = self.tree.removeLevel(self.root, level)
        result = self.tree.tree_to_list(new_root)
        expected = [1, [
            [2, [[8, []], [9, []], [10, []]]], 
            [3, []], 
            [4, [[11, []], [12, []]]]
        ]]
        print(self.tree.level_order_traversal(new_root), "After removal of Level:", level)
        self.assertEqual(result, expected, "Failed to remove nodes at given level")

    def test_remove_level_3(self):
        level = 3  # Remove nodes at level 3 (8, 9, 10, 11, 12)
        print(self.tree.level_order_traversal(self.root), "Level to remove:", level)
        new_root = self.tree.removeLevel(self.root, level)
        result = self.tree.tree_to_list(new_root)
        expected = [1, [
            [2, [[5, []], [6, []]]], 
            [3, []], 
            [4, [[7, []]]]
        ]]
        print(self.tree.level_order_traversal(new_root), "After removal of Level:", level)
        self.assertEqual(result, expected,"Failed to remove nodes at given level")

if __name__ == "__main__":
    unittest.main()
