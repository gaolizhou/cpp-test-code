//
// Created by lizgao on 6/22/18.
//

#include <memory>


namespace {
class B : public std::enable_shared_from_this<B> {
    std::shared_ptr<B> This() {
        return shared_from_this();
    }

};

class D : public B {
/*
    std::shared_ptr<D> This() {
        return shared_from_this();
    }
*/
};

}