
//
// Created by Narayan Ramjali on 9/29/15.
//
#include "Point.h"
#include "Cluster.h"

namespace Clustering {
    
    Cluster::Cluster(const Cluster &cluster) {
        size = cluster.size;
        LNodePtr currentNode;
        LNodePtr nodeUsedToCreate;
        LNodePtr copyNode;
        points = new LNode();
        currentNode = points;
        currentNode->p = cluster.points->p;
        currentNode->next = nullptr;
        copyNode = cluster.points->next;
        if (size > 1) {
            for (int i = 1; i < size; i++) {
                // Create new node
                nodeUsedToCreate = new LNode();
                nodeUsedToCreate->p = copyNode->p;
                
                // assign the new node to the list
                currentNode->next = nodeUsedToCreate;
                
                // Increment currentNode and copyNode
                currentNode = currentNode->next;
                copyNode = copyNode->next;
            }
        }
        *this = cluster;
    }
    
    Cluster &Cluster::operator=(const Cluster &cluster) {
        
        if (this == &cluster) {
            return *this;
        }
        
        
        return *this;
    }
    
    Cluster::~Cluster() {
        
    }
    
    void Cluster::add(PointPtr const &ptr) {
        
        LNodePtr newNode = new LNode;
        newNode->p = ptr;
        newNode->next = nullptr;
    }
    
    PointPtr const &Cluster::remove(PointPtr const &ptr) {
        
        
        // return <#initializer#>;
    }
    
    std::ostream &operator<<(std::ostream &ostream, const Cluster &cluster) {
        // return <#initializer#>;
    }
    
    std::istream &operator>>(std::istream &istream, Cluster &cluster) {
        //  return <#initializer#>;
    }
    
    Cluster &Cluster::operator+=(const Cluster &rhs) {
        //  return <#initializer#>;
    }
    
    Cluster &Cluster::operator+=(const Point &rhs) {
        
        return *this;
        // return <#initializer#>;
    }
    
    Cluster &Cluster::operator-=(const Point &rhs) {
        //  return <#initializer#>;
    }
    
    Cluster &Cluster::operator-=(const Cluster &rhs) {
        // return <#initializer#>;
    }
    
    
    const Cluster operator+(const Cluster &lhs, const Cluster &rhs) {
        Cluster newCluster = Cluster();
        
        
        return newCluster;
        //  return Clustering::Cluster();
    }
    
    const Cluster operator-(const Cluster &lhs, const Cluster &rhs) {
        Cluster newCluster = Cluster();
        
        
        return newCluster;
        
        //  return Clustering::Cluster();
    }
    
    const Cluster operator+(const Cluster &lhs, PointPtr const &rhs) {
        Cluster newCluster = Cluster();
        
        
        return newCluster;
        
        // return Clustering::Cluster();
    }
    
    const Cluster operator-(const Cluster &lhs, PointPtr const &rhs) {
        Cluster newCluster = Cluster();
        
        
        return newCluster;
        
        // return Clustering::Cluster();
    }
    
}

