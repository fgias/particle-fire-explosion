void Screen::clear() {
    memset(m_buffer1, 0, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));
}

for (int row=-Particle::RADIUS; row<=Particle::RADIUS; row++) {
    for (int col=-Particle::RADIUS; col<=Particle::RADIUS; col++) {
        int currentX = x + col;
        int currentY = y + row;
        m_buffer1[(currentY * SCREEN_WIDTH) + currentX ] = color;
    }
}

if (x < Particle::RADIUS || x >= SCREEN_WIDTH - Particle::RADIUS 
    || y < Particle::RADIUS || y >= SCREEN_HEIGHT - Particle::RADIUS) {
    return;
}