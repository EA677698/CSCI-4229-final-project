//
// Created by erickalanis on 11/28/24.
//

#include "arc.h"
#include "cuboid.h"


Arc::Arc(float radius, float startAngle, float endAngle, int definition, float width, float height, float depth) {
    float angleIncrement = (endAngle - startAngle) / definition;

    for (int i = 0; i < definition; ++i) {
        // Calculate the angles for the current segment
        float angle1 = startAngle + i * angleIncrement;
        float angle2 = startAngle + (i + 1) * angleIncrement;

        // Calculate the center points of the cuboid's inner and outer edges
        Vector3 innerP1((radius - width / 2) * cos(angle1), (radius - width / 2) * sin(angle1), 0.0f);
        Vector3 innerP2((radius - width / 2) * cos(angle2), (radius - width / 2) * sin(angle2), 0.0f);

        Vector3 outerP1((radius + width / 2) * cos(angle1), (radius + width / 2) * sin(angle1), 0.0f);
        Vector3 outerP2((radius + width / 2) * cos(angle2), (radius + width / 2) * sin(angle2), 0.0f);

        // Create a cuboid for this segment
        Cuboid *cuboid = new Cuboid(width, height, depth);

        for(unsigned int e = 0; e < 6; e++){
            cuboid->set_color(e, 0xFFFFFF >> i);
        }

        // Set the vertices of the cuboid
        cuboid->set_vector(BACK_BOTTOM_LEFT, innerP1 + Vector3(0, 0, -depth / 2));
        cuboid->set_vector(BACK_BOTTOM_RIGHT, outerP1 + Vector3(0, 0, -depth / 2));
        cuboid->set_vector(FRONT_BOTTOM_LEFT, innerP1 + Vector3(0, 0, depth / 2));
        cuboid->set_vector(FRONT_BOTTOM_RIGHT, outerP1 + Vector3(0, 0, depth / 2));

        cuboid->set_vector(BACK_TOP_LEFT, innerP2 + Vector3(0, height, -depth / 2));
        cuboid->set_vector(BACK_TOP_RIGHT, outerP2 + Vector3(0, height, -depth / 2));
        cuboid->set_vector(FRONT_TOP_LEFT, innerP2 + Vector3(0, height, depth / 2));
        cuboid->set_vector(FRONT_TOP_RIGHT, outerP2 + Vector3(0, height, depth / 2));

        // Finalize the cuboid and add it to the polyhedrons
        cuboid->construct_cuboid();
        polyhedrons.push_back(cuboid);
    }

    for(auto& polygon1 : polygons){
        polygon1.generate_texture_vertices();
    }
}