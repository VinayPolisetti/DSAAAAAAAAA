NODE root = getnode(1);
    root->l = getnode(2);
    root->r = getnode(3);
    root->l->r = getnode(4);
    root->r->l = getnode(5);
    root->r->r = getnode(6);
    root->l->r->l = getnode(10);
    root->r->r->l = getnode(7);
    root->r->r->r = getnode(24);
    root->r->r->l->l = getnode(9);
    root->r->r->l->r = getnode(8);
    root->r->r->r->r = getnode(25);