// Copyright (c) 2020 CS126SP20. All rights reserved.

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <cinder/Rand.h>
#include "../apps/shape.cpp"

TEST_CASE("Get line coordinates", "[vector]") {
  Shape line(Color(1, 1, 1), ShapeType::line, 50, 50);
  line.UpdateWithoutClearing(100, 100);
  vector<int> line_coords = {50, 50, 100, 100};
  REQUIRE(line.GetShapeCoordinates() == line_coords);
}

TEST_CASE("Get rect coordinates", "[vector]") {
  Shape rect(Color(1, 1, 1), ShapeType::rect, 50, 50);
  rect.UpdateWithoutClearing(100, 100);
  vector<int> rect_coords = {50, 50, 100, 100};
  REQUIRE(rect.GetShapeCoordinates() == rect_coords);
}

TEST_CASE("Get scribble coordinates", "[vector]") {
  Shape scribble(Color(1, 1, 1), ShapeType::scribble, 50, 50);
  scribble.UpdateWithoutClearing(100, 100);
  vector<int> scribble_coords = {50, 50, 100, 100};
  REQUIRE(scribble.GetShapeCoordinates() == scribble_coords);
}