#include <gtest/gtest.h>
#include "scene_manager.h"

TEST(SceneManagerTest, AddScene) {
    SceneManager manager;
    manager.addScene("Scene1");
    ASSERT_EQ(manager.getSceneCount(), 1);
}

TEST(SceneManagerTest, RemoveScene) {
    SceneManager manager;
    manager.addScene("Scene1");
    manager.removeScene("Scene1");
    ASSERT_EQ(manager.getSceneCount(), 0);
}

TEST(SceneManagerTest, RenderScene) {
    SceneManager manager;
    manager.addScene("Scene1");
    ASSERT_NO_THROW(manager.renderScene("Scene1"));
}