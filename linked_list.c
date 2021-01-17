#include <assert.h>
#include "linked_list.h"

void ll_init(struct ll_node *node) {
    assert(node != NULL);
    // TODO: Implement your solution here.
    node->isHead = true;
    node-> next = node;
    node-> prev = node;
}

bool ll_has_next(struct ll_node *node) {
    assert(node != NULL);
    // TODO: Implement your solution here.
    return node->next->isHead == true ? false : true;
}

bool ll_has_prev(struct ll_node *node) {
    assert(node != NULL);
    // TODO: Implement your solution here.
    return node->isHead == true ? false : true;
}

struct ll_node *ll_next(struct ll_node *node) {
    assert(node != NULL);
    // TODO: Implement your solution here.
    if (ll_has_next(node)) {
        return node->next;
    } else {
        return NULL;
    }
}

struct ll_node *ll_prev(struct ll_node *node) {
    assert(node != NULL);
    // TODO: Implement your solution here.
    if (ll_has_prev(node)) {
        return node->prev;
    } else {
        return NULL;
    }
}

size_t ll_size(struct ll_node *head) {
    assert(head != NULL);
    // TODO: Implement your solution here.
    assert(head->isHead);
    size_t size = 1;
    while (ll_has_next(head)){
        size++;
        head = head -> next;
    }
    return size;
}

struct ll_node *ll_head(struct ll_node *list) {
    assert(list != NULL);
    // TODO: Implement your solution here.
    while (!list->isHead){
        list = list -> next;
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
        node = node -> next;
        index--;
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
    if (existing -> isHead){
        existing -> isHead = false;
        new -> isHead = true;
    }
    struct ll_node* original_prev = existing -> prev;
    original_prev -> next = new;
    existing -> prev = new;
    new -> next = existing;
    new -> prev = original_prev;
}

void ll_insert_after(struct ll_node *new, struct ll_node *existing) {
    assert(new != NULL);
    assert(existing != NULL);
    // TODO: Implement your solution here.

}

void ll_insert_first(struct ll_node *new, struct ll_node *list) {
    assert(new != NULL);
    assert(list != NULL);
    // TODO: Implement your solution here.
    if (ll_size(list) == 1){
        list->isHead = false;
        new->isHead = true;
        new->next = list;
        new->prev = list;
        list->next = new;
        list->prev = new;
    } else {
        struct ll_node* head = ll_head(list);
        struct ll_node* prev = head->prev;
        prev->next = new;
        head->prev = new;
        new->prev = prev;
        new->next = head;
    }
}

void ll_insert_last(struct ll_node *new, struct ll_node *list) {
    assert(new != NULL);
    assert(list != NULL);
    // TODO: Implement your solution here.
    if (ll_size(list) == 1){
        new->next = list;
        new->prev = list;
        list->next = new;
        list->prev = new;
    } else {
        struct ll_node* tail = ll_tail(list);
        struct ll_node* next = tail->next;
        tail->next = new;
        next->prev = new;
        new->next = next;
        new->prev = tail;
    }

}

void ll_remove(struct ll_node *node) {
    assert(node != NULL);
    // TODO: Implement your solution here.
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
