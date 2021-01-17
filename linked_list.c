#include <assert.h>
#include "linked_list.h"

void ll_init(struct ll_node *node) {
    assert(node != NULL);
    // TODO: Implement your solution here.
    node->next = NULL;
    node->prev = NULL;
}

bool ll_has_next(struct ll_node *node) {
    assert(node != NULL);
    // TODO: Implement your solution here.
    return node->next != NULL;
}

bool ll_has_prev(struct ll_node *node) {
    assert(node != NULL);
    // TODO: Implement your solution here.
    return node->prev != NULL;
}

struct ll_node *ll_next(struct ll_node *node) {
    assert(node != NULL);
    // TODO: Implement your solution here.
    return node->next;
}

struct ll_node *ll_prev(struct ll_node *node) {
    assert(node != NULL);
    // TODO: Implement your solution here.
    return node->prev;
}

size_t ll_size(struct ll_node *head) {
    assert(head != NULL);
    // TODO: Implement your solution here.
    int size = 1;
    while (ll_has_next(head)){
        head = head->next;
        size++;
    }
    return size;
}

struct ll_node *ll_head(struct ll_node *list) {
    assert(list != NULL);
    // TODO: Implement your solution here.
    while (ll_has_prev(list)){
        list = list -> prev;
    }
    return list;
}

struct ll_node *ll_tail(struct ll_node *list) {
    assert(list != NULL);
    // TODO: Implement your solution here.
    while (ll_has_next(list)){
        list = list -> next;
    }
    return list;
}

struct ll_node *ll_get(struct ll_node *node, size_t index) {
    assert(node != NULL);
    // TODO: Implement your solution here.
    if (index == 0){
        return node;
    }
    while (ll_has_next(node)){
        index--;
        node = node -> next;
        if (index == 0){
            return node;
        }
    }
    return NULL;
}

void ll_insert_before(struct ll_node *new, struct ll_node *existing) {
    assert(new != NULL);
    assert(existing != NULL);
    // TODO: Implement your solution here.
    struct ll_node* head = ll_head(existing);
    if (head == existing){
        ll_insert_first(new,existing);
    } else {
        struct ll_node* prev = existing->prev;
        prev->next = new;
        existing->prev = new;
        new->next = existing;
        new->prev = prev;
    }
}

void ll_insert_after(struct ll_node *new, struct ll_node *existing) {
    assert(new != NULL);
    assert(existing != NULL);
    // TODO: Implement your solution here.
    struct ll_node* tail = ll_tail(existing);
    if (tail == existing){
        ll_insert_last(new, existing);
    } else {
        struct ll_node* next = existing->next;
        existing->next = new;
        next->prev = new;
        next->next = next;
        new->prev = existing;
    }
}

void ll_insert_first(struct ll_node *new, struct ll_node *list) {
    assert(new != NULL);
    assert(list != NULL);
    // TODO: Implement your solution here.
    struct ll_node* tail = ll_tail(list);
    struct ll_node* head = ll_head(list);
    new -> prev = NULL;
    new -> next = head;
    tail -> next = NULL;
    head -> prev = new;
}

void ll_insert_last(struct ll_node *new, struct ll_node *list) {
    assert(new != NULL);
    assert(list != NULL);
    // TODO: Implement your solution here.
    struct ll_node* tail = ll_tail(list);
    struct ll_node* head = ll_head(list);
    new -> prev = tail;
    new -> next = NULL;
    tail -> next = new;
    head -> prev = NULL;
}

void ll_remove(struct ll_node *node) {
    assert(node != NULL);
    // TODO: Implement your solution here.
    struct ll_node* head = ll_head(node);
    struct ll_node* tail = ll_tail(node);
    if (head == tail){
        node->prev = NULL;
        node->next = NULL;
    } else if (node == head){
        node->next->prev = NULL;
        node->next = NULL;
    } else if (node == tail){
        node->prev->next = NULL;
        node->prev = NULL;
    } else {
        struct ll_node* next = node->next;
        struct ll_node* prev = node->prev;
        prev->next = next;
        next->prev = prev;
        node->next = NULL;
        node->prev = NULL;
    }
}

struct ll_node *ll_min(struct ll_node *list, ll_comparator_t comparator) {
    assert(list != NULL);
    assert(comparator != NULL);
    // TODO: Implement your solution here.
    return NULL;
}

struct ll_node *ll_max(struct ll_node *list, ll_comparator_t comparator) {
    assert(list != NULL);
    assert(comparator != NULL);
    // TODO: Implement your solution here.
    return NULL;
}

struct ll_node *ll_filter(struct ll_node *list, ll_predicate_t predicate) {
    assert(list != NULL);
    assert(predicate != NULL);
    // TODO: Implement your solution here.
    return NULL;
}
