class Codec {
public:

    // Encodes a tree to a single string.
    void serializeHelper(TreeNode* root, string &s) {
        if (root == nullptr) {
            s += "#,";
            return;
        }

        s += to_string(root->val) + ",";
        serializeHelper(root->left, s);
        serializeHelper(root->right, s);
    }

    string serialize(TreeNode* root) {
        string s;
        serializeHelper(root, s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserializeHelper(stringstream &ss) {
        string val;
        getline(ss, val, ',');

        if (val == "#")
            return nullptr;

        TreeNode* root = new TreeNode(stoi(val));

        root->left = deserializeHelper(ss);
        root->right = deserializeHelper(ss);

        return root;
    }

    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return deserializeHelper(ss);
    }
};