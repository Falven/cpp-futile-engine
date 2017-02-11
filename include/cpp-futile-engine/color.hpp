class color
{
public:
	color(const double red, const double green, const double blue, const double alpha)
		: red_(red), green_(green), blue_(blue), alpha_(alpha) {}

	~color() {}

	double get_red() { return red_; }

	void set_red(const double red) { red_ = red; }

	double get_green() { return green_; }

	void set_green(const double green) { green_ = green; }

	double get_blue() { return blue_; }

	void set_blue(const double blue) { blue_ = blue; }

	double get_alpha() { return alpha_; }

	void set_alpha(const double alpha) { alpha_ = alpha; }

private:
	double red_;
	double green_;
	double blue_;
	double alpha_;
};