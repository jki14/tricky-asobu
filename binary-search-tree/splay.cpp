#include <algorithm>
#include <cassert>
#include <cstdio>

class SplayTree{
    public:
    class SplayNode{
        public:
        long long value;
        long long minimum;
        long long delta;
        int reversed;
        SplayNode *parent;
        SplayNode *child[2];
        int nsize;
        SplayNode(const long long v) : value(v), minimum(v), delta(0LL), reversed(0), nsize(1) {
            this->parent = nullptr;
            this->child[0] = nullptr;
            this->child[1] = nullptr;
        }
        ~SplayNode(){
            if (this->child[0] != nullptr) {
                delete this->child[0];
            }
            if (this->child[1] != nullptr) {
                delete this->child[1];
            }
        }
        int get_child_id() const {
            if (this->parent == nullptr) return -1;
            if (this == this->parent->child[0]) return 0;
            if (this == this->parent->child[1]) return 1;
            assert(false);
            return -1;
        }
        void flush(){
            // customized operation - interval reverse
            if (this->reversed != 0) {
                std::swap(this->child[0], this->child[1]);
                if (this->child[0] != nullptr) {
                    this->child[0]->reversed ^= 1;
                }
                if (this->child[1] != nullptr) {
                    this->child[1]->reversed ^= 1;
                }
                this->reversed = 0;
            }
            // customized operation - interval increment
            if (this->delta != 0) {
                this->value += this->delta;
                if (this->child[0] != nullptr) {
                    this->child[0]->delta += this->delta;
                }
                if (this->child[1] != nullptr) {
                    this->child[1]->delta += this->delta;
                }
                this->delta = 0;
            }
        }
        void update() {
            this->nsize = 1;
            this->minimum = this->value;
            for (int i = 0; i < 2; ++i) {
                if (this->child[i] != nullptr) {
                    this->nsize += this->child[i]->nsize;
                    this->child[i]->parent = this;
                    // customized operation - cache minimum
                    this->minimum = std::min(this->child[i]->minimum + this->child[i]->delta, this->minimum);
                }
            }
        }
        SplayNode* rotate(const int cid) {
            // rotate operation
            SplayNode *node = this->child[cid];
            SplayNode *temp = node->child[cid ^ 1];
            node->child[cid ^ 1] = this;
            this->child[cid] = temp;
            // update grandparent
            SplayNode *grandparent = this->parent;
            if (grandparent != nullptr) {
                grandparent->child[this->get_child_id()] = node;
            }
            // update node values
            this->update();
            node->update();
            if (grandparent != nullptr) {
                grandparent->update();
            } else {
                node->parent = nullptr;
            }
            return node;
        }
        SplayNode* insert(const int cursor, const long long value) {
            this->flush();
            int leftsize = this->nsize;
            if (this->child[1] != nullptr) {
                leftsize -= this->child[1]->nsize;
            }
            SplayNode *nodeptr = nullptr;
            if (cursor < leftsize) {
                if (this->child[0] != nullptr) {
                    nodeptr = this->child[0]->insert(cursor, value);
                } else {
                    if (cursor == 0) {
                        nodeptr = new SplayNode(value);
                        this->child[0] = nodeptr;
                    } else {
                        assert(false); 
                    }
                }
            } else {
                if (this->child[1] != nullptr) {
                    nodeptr = this->child[1]->insert(cursor - leftsize, value);
                } else {
                    if (cursor == leftsize) {
                        nodeptr = new SplayNode(value);
                        this->child[1] = nodeptr;
                    } else {
                        assert(false);
                    }
                }
            }
            this->update();
            return nodeptr;
        }
        SplayNode* select(const int offset) {
            this->flush();
            int leftsize = this->nsize;
            if (this->child[1] != nullptr) {
                leftsize -= this->child[1]->nsize;
            }
            if (offset < leftsize) {
                assert(this->child[0] != nullptr);
                return this->child[0]->select(offset);
            } else if (offset > leftsize) {
                assert(this->child[1] != nullptr);
                return this->child[1]->select(offset - leftsize);
            } else {
                return this;
            }
        }
        void show() {
            this->flush();
            if (this->child[0] != nullptr) {
                this->child[0]->show();
            }
            fprintf(stderr, "%lld", this->value);
            if (this->parent != nullptr) {
                if (this->get_child_id() == 0) {
                    fprintf(stderr, " -(%lld)", this->parent->value);
                } else {
                    fprintf(stderr, " (%lld)-", this->parent->value);
                }
            } else {
                fprintf(stderr, " (nullptr)");
            }
            fprintf(stderr, "\n");
            if (this->child[1] != nullptr) {
                this->child[1]->show();
            }
        }
    } *root;
    SplayTree() {
        this->root = nullptr;
    }
    ~SplayTree() {
        if (this->root != nullptr) {
            delete this->root;
        }
    }
    void splay(SplayNode *node) {
        this->splay(node, &this->root);
    }
    void splay(SplayNode *node, SplayNode **destination) {
        while (node != *destination) {
            if (node->parent == nullptr) {
                assert(false);
            }
            if (node->parent != *destination) {
                //double rotate
                if (node->parent->parent == nullptr) {
                    assert(false);
                }
                int cid = node->get_child_id();
                if (cid == node->parent->get_child_id()) {
                    node->parent->parent->rotate(cid);
                    node->parent->rotate(cid);
                } else {
                    node->parent->rotate(cid);
                    node->parent->rotate(cid ^ 1);
                }
                if (node->parent == nullptr) {
                    this->root = node;
                }
            } else {
                //single rotate
                node->parent->rotate(node->get_child_id());
                if (node->parent == nullptr) {
                    this->root = node;
                }
            }
        }
        while (node->parent != nullptr) {
            node->parent->update();
            node = node->parent;
        }
    }
    void insert(const int cursor, const long long value) {
        if (this->root != nullptr) {
            SplayNode *nodeptr = this->root->insert(cursor, value);
            this->splay(nodeptr);
        } else {
            if (cursor == 0) {
                this->root = new SplayNode(value);
            }
        }
    }
    void erase(SplayNode *node) {
        while (true) {
            if (node->child[0] != nullptr) {
                SplayNode *candidate = node->child[0];
                candidate->flush();
                while (candidate->child[1] != nullptr) {
                    candidate = candidate->child[1];
                    candidate->flush();
                }
                node->value = candidate->value;
                node = candidate;
            } else if (node->child[1] != nullptr) {
                SplayNode *candidate = node->child[1];
                candidate->flush();
                while (candidate->child[0] != nullptr) {
                    candidate = candidate->child[0];
                    candidate->flush();
                }
                node->value = candidate->value;
                node = candidate;
            } else {
                if (node->parent != nullptr) {
                    node->parent->child[node->get_child_id()] = nullptr;
                    SplayNode *temp = node->parent;
                    while (temp != nullptr) {
                        temp->update();
                        temp = temp->parent;
                    }
                    this->splay(node->parent);
                } else {
                    this->root = nullptr;
                }
                delete node;
                break;
            }
        }
    }
    SplayNode *select(const int offset) {
        if (this->root != nullptr) {
            return this->root->select(offset);
        } else {
           assert(false); 
        }
    }
    void show() {
        fprintf(stderr, "----Splay Tree----\n");
        if (this->root != nullptr) {
            this->root->show();
        } else {
            fprintf(stderr, "nil\n");
        }
    }
};
