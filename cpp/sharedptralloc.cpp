#include <iostream>
#include <memory>
#include <array>


void* operator new(std::size_t sz) {
    void *ptr = std::malloc(sz);
    std::printf("::new(%p, %zu)\n", ptr, sz);
    return ptr;
}


void operator delete(void* ptr) noexcept {
    std::printf("::delete(%p)\n", ptr);
    std::free(ptr);
}


void operator delete(void* ptr, std::size_t sz) noexcept {
    std::printf("::delete(%p, %zu)\n", ptr, sz);
    std::free(ptr);
}


struct X {
    std::array<int, 5000> array;

    static void operator delete(void* ptr, std::size_t sz) noexcept {
        std::printf("X::delete(%p, %zu)\n", ptr, sz);
        ::operator delete(ptr, sz);
    }
};


int main() {
    {
        std::weak_ptr<X> wp1;
        {
            std::cout << "Create p1 shared_ptr with constructor" << std::endl;
            std::shared_ptr<X> p1 = std::shared_ptr<X>(new X());

            std::cout << "Assign p1 to weak_ptr wp1" << std::endl;
            wp1 = p1;

            std::cout << "p1 goes out of scope" << std::endl;
        }

		if (wp1.lock())
		{
			std::cout << "wp1 can lock resources" << std::endl;
		}
		else
		{
			std::cout << "wp1 cannot lock" << std::endl;
		}
        std::cout << "wp1 goes out of scope" << std::endl;
    }

    {
        std::weak_ptr<X> wp2;
        {
            std::cout << "Create p2 with make_shared" << std::endl;
            std::shared_ptr<X> p2 = std::make_shared<X>();

            std::cout << "Assign p2 to weak_ptr wp2" << std::endl;
            wp2 = p2;

            std::cout << "p2 goes out of scope" << std::endl;
        }

		if (wp2.lock())
		{
			std::cout << "wp1 can lock resources" << std::endl;
		}
		else
		{
			std::cout << "wp1 cannot lock" << std::endl;
		}
        std::cout << "wp2 goes out of scope" << std::endl;
    }

    return 0;
}
