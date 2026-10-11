#pragma once

#include <string>
#include <vector>

/**
 * Simple string wrapper class fulfilling the problem requirements.
 * Internally stores data in a std::string for safety and convenience.
 */
class str {
private:
    std::string data_; // underlying storage
public:
    // Default constructor – empty string
    str() : data_() {}

    // Construct from a single character
    explicit str(const char &c) : data_(1, c) {}

    // Construct from a C‑style string (rvalue reference to const char*)
    // The reference qualifier is kept to match the required signature.
    explicit str(const char *&& s_) : data_(s_) {}

    // Assignment from C‑style string (rvalue reference)
    str &operator=(const char *&& s_) {
        data_ = s_;
        return *this;
    }

    // Copy constructor and copy assignment (defaulted)
    str(const str &other) = default;
    str &operator=(const str &other) = default;

    // Element access – no bounds checking, mirroring std::string behavior
    char &operator[](size_t pos) { return data_[pos]; }

    // Length of the string
    size_t len() const { return data_.size(); }

    // Join a vector of str objects using this instance as the delimiter
    str join(const std::vector<str> &strs) const {
        if (strs.empty()) return str();
        std::string result = strs.front().data_;
        for (size_t i = 1; i < strs.size(); ++i) {
            result += data_;               // delimiter
            result += strs[i].data_;        // next element
        }
        return str(result.c_str());
    }

    // Slice [l, r) – if out of range, behaviour mirrors std::string::substr
    str slice(size_t l, size_t r) const {
        if (l > data_.size()) l = data_.size();
        if (r > data_.size()) r = data_.size();
        if (r < l) r = l;
        return str(data_.substr(l, r - l).c_str());
    }

    // Destructor – defaulted (handled by std::string)
    ~str() = default;
};

