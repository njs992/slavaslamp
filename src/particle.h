#pragma once

#include <ctypes>
#include <memory>
#include <unordered_map>

#ifndef X_MAX
#define X_MAX 24
#endif

#ifndef Y_MAX
#define Y_MAX 32
#endif

struct Position
{
	uint32_t x_pos;
	uint32_t y_pos;
};

class Particle
{
public:
	Particle() : mp_position( std::make_shared< Position >( 0, 0 ), mp_temperature( std::make_shared< double >( 20.0 ) ) {}
	~Particle() {}

	const shared_ptr< Position > get_position() { return mp_position; }
	const shared_ptr< double > get_temperature() { return mp_temperature; }

	void simulate_temperature( &std::unordered_map< Position, shared_ptr< Particle > > volume );
	void simulate_displacement_vector();
private:
	shared_ptr< Position > mp_position;
	shared_ptr< double > mp_temperature;
};
