#include "AnimateUtils.h"
#include "../ImageUtils/ImageUtils.h"

const unsigned int AnimateUtils::max_anim_frames = 999;
const unsigned int AnimateUtils::max_numb_digits = 4;

Animate *AnimateUtils::createAnimate(std::string &path, std::string &pattern,
                                     std::string &format, unsigned int numb_anim_frames, float delay)
{

    Vector<SpriteFrame *> sprite_frames = std::move(AnimateUtils::createVectorSpriteFrames(path, pattern, format,
                                                                                           numb_anim_frames));

    Animation *animation = Animation::createWithSpriteFrames(sprite_frames, delay);
    return Animate::create(animation);
}

std::string AnimateUtils::createFileName(std::string &path, std::string &pattern,
                                         std::string &format, unsigned int number)
{
    if (number > AnimateUtils::max_anim_frames)
    {
        throw std::out_of_range("big input number");
    }

    char number_str[AnimateUtils::max_numb_digits];
    memset(number_str, '\0', AnimateUtils::max_numb_digits);
    sprintf(number_str, "%i", number);

    return path + pattern + number_str + format;
}

Vector<SpriteFrame *>AnimateUtils::createVectorSpriteFrames(std::string &path, std::string &pattern,
                                                            std::string &format,
                                                            unsigned int numb_anim_frames)
{
    if (numb_anim_frames > AnimateUtils::max_anim_frames)
    {
        throw std::out_of_range("big input numb_anim_frames");
    }
    Vector<SpriteFrame *> sprite_frames(numb_anim_frames);

    std::string frame_filename = std::move(AnimateUtils::createFileName(path, pattern, format, 1));
    Size image_size = ImageUtils::getSize(frame_filename);

    for (unsigned int i = 1; i < numb_anim_frames; ++i)
    {
        frame_filename = std::move(AnimateUtils::createFileName(path, pattern, format, 1));
        SpriteFrame *frame = SpriteFrame::create(frame_filename,
                                                 Rect(0, 0, image_size.width, image_size.height));
        if (frame == nullptr)
        {
            std::string err = "cannot create frame form " + frame_filename;
            throw std::invalid_argument(err);
        }

        sprite_frames.pushBack(frame);
    }

    return sprite_frames;
}
