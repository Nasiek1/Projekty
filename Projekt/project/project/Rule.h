#pragma once
#include<memory>
#include<string>
#include<vector>
#include<cctype>
class Rule
{

public:
	typedef std::shared_ptr<Rule> ptr;
	typedef std::shared_ptr<const Rule> const_ptr;
	operator bool()
	{
		return succeeded_;
	}
	size_t size(unsigned int right) const
	{
		return right_[right].size();
	}
private:
	std::string left_;
	std::vector<std::vector<std::string> > right_;
	bool succeeded_;
	Rule(const std::string& left, const std::string& right)
		: left_(left)
	{
		right_.push_back(std::vector<std::string>(1, right));
	}
	Rule(const std::string &str)
	{
		unsigned int i = 0;
		while (i < str.size() && std::isspace(str[i])) {
			++i;
		}
		// Get left-hand side
		while (i < str.size() && std::isalnum(str[i])) {
			left_.push_back(str[i]);
			++i;
		}
		if (!(succeeded_ = !left_.empty())) {
			return;
		}
		while (i < str.size() && std::isspace(str[i])) {
			++i;
		}
		// Get arrow
		if (!(succeeded_ = str.substr(i, 2) == "->")) {
			return;
		}
		i += 2;
		while (i < str.size() && std::isspace(str[i])) {
			++i;
		}
		// Get right-hand side
		while (i < str.size()) {
			bool added = false;
			while (i < str.size() && str[i] != '|') {
				std::string symbol;
				while (i < str.size() && !std::isspace(str[i]) && str[i] != '|') {
					symbol.push_back(str[i]);
					++i;
				}
				if (!symbol.empty()) {
					if (!added) {
						right_.push_back(std::vector<std::string>());
						added = true;
					}
					right_.back().push_back(symbol);
				}
				while (i < str.size() && std::isspace(str[i])) {
					++i;
				}
			}
			if (i < str.size()) {
				++i;
			}
		}
	}
public:
	static ptr create(const std::string& left, const std::string& right)
	{
		return ptr(new Rule(left, right));
	}
	static ptr create(const std::string& line)
	{
		return ptr(new Rule(line));
	}
	const std::string& left() const
	{
		return left_;
	}
	const std::vector<std::vector<std::string> >& right() const
	{
		return right_;
	}
	friend std::ostream& operator <<(std::ostream& os, const Rule& r)
	{
		os << r.left_ << " -> ";
		unsigned int i = 0;
		for (const std::vector<std::string>& alternative : r.right_) {
			for (const std::string& symbol : alternative) {
				os << symbol << " ";
			}
			if (i++ < r.right_.size() - 1) {
				os << "| ";
			}
		}
		return os;
	}
	Rule();
	~Rule();
};

