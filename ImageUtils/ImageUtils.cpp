#include "ImageUtils.h"

std::string ImageUtils::prefix_err_create_sprite = "ERROR: Can not open ";

Size ImageUtils::getSize(const std::string &filename)
{
    Sprite *sprite = Sprite::create(filename);
    if(sprite == nullptr)
    {
        throw std::invalid_argument(prefix_err_create_sprite + filename);
    }

    return sprite->getContentSize();
}

bool ImageUtils::isExist(const std::string &filename)
{
    Sprite *sprite = Sprite::create(filename);
    if(sprite == nullptr) { return false; }
    return true;
}
