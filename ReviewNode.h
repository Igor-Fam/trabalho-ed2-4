#ifndef REVIEWNODE_H
#define REVIEWNODE_H

#include <string>
#include "fileManager.h"

class ReviewNode
{
private:
    int position;
    string id;
public:   
    ReviewNode() {}

    ReviewNode(int position_, string id_) {
        position = position_;
        id = id_;
    }

    string getId(){
        return id;
    }

    void getReview() {
        acessaRegistro(position);
    }

    friend class BTree;
    friend class BNode;
    friend class VPTree;
    friend class VPNode;

    static ReviewNode* importNodes(int N) {
        ifstream file;
        file.open("tiktok_app_reviews.bin");
        file.seekg(0, ios::end);
        int max = (file.tellg() / sizeof(Review)) - 1;
        ReviewNode* ref = new ReviewNode[N];
        srand(time(0));
        Review* reg = new Review;
        for(int i = 0; i < N; i++){
            int random = (rand()) % max;
            file.seekg(random * sizeof(Review), ios::beg);
            file.read(reinterpret_cast<char*>(reg), 90);
            ref[i].id = reg->review_id;
            ref[i].position = random;
        }

        delete reg;
        


        file.close();
        return ref;
    }
};

#endif