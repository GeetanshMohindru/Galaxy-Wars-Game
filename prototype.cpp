#include <glut.h>
#include <vector>
#include <ctime>
#include <string> // added for kill count text
#include <cmath>  // added for cos/sin

const int WIDTH = 800;
const int HEIGHT = 600;
const float PLAYER_WIDTH = 50.0f;
const float PLAYER_HEIGHT = 20.0f;
const float BULLET_RADIUS = 5.0f;
const float ENEMY_SIZE = 30.0f;

float playerX = WIDTH / 2.0f;
float bulletSpeed = 5.0f;
float enemySpeed = 1.0f;
int killCount = 0; // ✅ added kill counter

struct Bullet {
    float x, y;
    bool alive;
};

struct Enemy {
    float x, y;
    bool alive;
};

std::vector<Bullet> bullets;
std::vector<Enemy> enemies;

void drawRect(float x, float y, float w, float h) {
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + w, y);
    glVertex2f(x + w, y + h);
    glVertex2f(x, y + h);
    glEnd();
}

void drawCircle(float x, float y, float radius) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i += 10) {
        float angle = i * 3.14159f / 180;
        glVertex2f(x + cos(angle) * radius, y + sin(angle) * radius);
    }
    glEnd();
}

void drawText(float x, float y, const std::string& text) { // ✅ helper function to draw text
    glColor3f(1, 1, 1);
    glRasterPos2f(x, y);
    for (char c : text)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
}

void spawnEnemy() {
    Enemy e = { float(rand() % (WIDTH - int(ENEMY_SIZE))), float(HEIGHT), true };
    enemies.push_back(e);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0, 0, 1);
    drawRect(playerX, 20, PLAYER_WIDTH, PLAYER_HEIGHT);

    glColor3f(1, 1, 0);
    for (auto& b : bullets)
        if (b.alive) drawCircle(b.x, b.y, BULLET_RADIUS);

    glColor3f(1, 0, 0);
    for (auto& e : enemies)
        if (e.alive) drawRect(e.x, e.y, ENEMY_SIZE, ENEMY_SIZE);

    drawText(10, HEIGHT - 30, "Kills: " + std::to_string(killCount)); // ✅ show kill counter

    glutSwapBuffers();
}

void update(int value) {
    for (auto& b : bullets) {
        if (b.alive) b.y += bulletSpeed;
        if (b.y > HEIGHT) b.alive = false;
    }

    for (auto& e : enemies) {
        if (e.alive) e.y -= enemySpeed;
        if (e.y < 0) e.alive = false;
    }

    for (auto& b : bullets) {
        for (auto& e : enemies) {
            if (b.alive && e.alive &&
                b.x > e.x && b.x < e.x + ENEMY_SIZE &&
                b.y > e.y && b.y < e.y + ENEMY_SIZE) {
                b.alive = false;
                e.alive = false;
                killCount++; // ✅ increment kill counter
            }
        }
    }

    if (rand() % 100 < 2) spawnEnemy();

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

void keyboard(int key, int, int) {
    if (key == GLUT_KEY_LEFT && playerX > 0)
        playerX -= 20;
    if (key == GLUT_KEY_RIGHT && playerX < WIDTH - PLAYER_WIDTH)
        playerX += 20;
    glutPostRedisplay();
}

void keyPressed(unsigned char key, int, int) {
    if (key == ' ') {
        bullets.push_back({ playerX + PLAYER_WIDTH / 2, 40, true });
    }
}

void init() {
    glClearColor(0, 0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, WIDTH, 0, HEIGHT);
    srand(unsigned(time(0)));
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Block Shooting Game");
    init();
    glutDisplayFunc(display);
    glutSpecialFunc(keyboard);
    glutKeyboardFunc(keyPressed);
    glutTimerFunc(0, update, 0);
    glutMainLoop();
    return 0;
}
