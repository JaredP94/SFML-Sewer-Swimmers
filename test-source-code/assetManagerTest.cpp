#include "assetManager.h"
#include "gtest/gtest.h"
#include <SFML/Graphics.hpp>

using sf::Texture;

TEST(AssetManager, ExistingFileLoadsCorrectly)
{
	enum class Test{Test1};
	AssetManager<Texture,Test> loadTextureTest;
	EXPECT_NO_THROW(loadTextureTest.loadAsset(Test::Test1, "test_image.png"));
}

TEST(AssetManager, FileNameNotFoundThrowsRunTimeError)
{
	enum class Test{Test2};
	AssetManager<Texture,Test> loadTextureTest;
	EXPECT_THROW(loadTextureTest.loadAsset(Test::Test2, "test.png"),std::runtime_error);
}


