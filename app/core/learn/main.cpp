// app includes
// // env
#include "param/parameters.h"
#include "core/core.h"
// // learn
#include "core/learn/core.h"

int main () {
	c0p::Learn::init();
	c0p::Learn::run();
	c0p::Learn::save();
}
