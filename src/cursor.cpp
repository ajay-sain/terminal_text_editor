#include "../include/cursor.hpp"

namespace TerminalTextEditor
{
    Cursor *Cursor::_m_instance;
    

    Cursor::Cursor()
    {
        _m_window = Window::getInstance();
    }

    Cursor::~Cursor() {}

    Cursor::Cursor(const Cursor &c)
    {
        if (0 < c._m_x < _m_window->getWindowWidth())
            this->_m_x = c._m_x;
        if (0 < c._m_y < _m_window->getWindowHeight())
            this->_m_y = c._m_y;
    }

    Cursor &Cursor::operator=(const Cursor &c)
    {
        Cursor newObj(c);
        return newObj;
    }

    void Cursor::move(Cursor c)
    {
        move(c._m_x, c._m_y);
    }

    void Cursor::move(int x, int y)
    {
        if (0 < x < _m_window->getWindowWidth())
            this->_m_x = x;
        if (0 < y < _m_window->getWindowHeight())
            this->_m_y = y;
    }

    void Cursor::move(int c)
    {
        switch (c)
        {
        case ARROW_UP:
            if (_m_y > 0)
                _m_y--;
            break;
        case ARROW_DOWN:
            if (_m_y < _m_window->getWindowHeight())
                _m_y++;
            break;
        case ARROW_LEFT:
            if (_m_x > 0)
                _m_x--;
            break;
        case ARROW_RIGHT:
            if (_m_x < _m_window->getWindowWidth())
                _m_x++;
            break;
        }
    }

    Cursor *Cursor::getInstance()
    {
        if (_m_instance == NULL)
            _m_instance = new Cursor();
        return _m_instance;
    }

    int Cursor::getX()
    {
        return _m_x;
    }

    int Cursor::getY()
    {
        return _m_y;
    }
};