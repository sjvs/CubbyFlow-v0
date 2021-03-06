/*************************************************************************
> File Name: Box3.h
> Project Name: CubbyFlow
> This code is based on Jet Framework that was created by Doyub Kim.
> References: https://github.com/doyubkim/fluid-engine-dev
> Purpose: 3-D box geometry.
> Created Time: 2017/06/21
> Copyright (c) 2018, Chan-Ho Chris Ohk
*************************************************************************/
#ifndef CUBBYFLOW_BOX3_H
#define CUBBYFLOW_BOX3_H

#include <Core/Surface/Surface3.h>

namespace CubbyFlow
{
	//!
	//! \brief 3-D box geometry.
	//!
	//! This class represents 3-D box geometry which extends Surface3 by overriding
	//! surface-related queries. This box implementation is an axis-aligned box
	//! that wraps lower-level primitive type, BoundingBox3D.
	//!
	class Box3 final : public Surface3
	{
	public:
		class Builder;

		//! Bounding box of this box.
		BoundingBox3D bound = BoundingBox3D(Vector3D(), Vector3D(1.0, 1.0, 1.0));

		//! Constructs (0, 0, 0) x (1, 1, 1) box.
		Box3(const Transform3& transform = Transform3(), bool isNormalFlipped = false);

		//! Constructs a box with given \p lowerCorner and \p upperCorner.
		Box3(const Vector3D& lowerCorner, const Vector3D& upperCorner,
			const Transform3& transform = Transform3(), bool isNormalFlipped = false);

		//! Constructs a box with BoundingBox3D instance.
		explicit Box3(const BoundingBox3D& boundingBox, const Transform3& transform = Transform3(), bool isNormalFlipped = false);

		//! Copy constructor.
		Box3(const Box3& other);

		//! Returns builder fox Box3.
		static Builder GetBuilder();

	protected:
		// Surface3 implementations
		Vector3D ClosestPointLocal(const Vector3D& otherPoint) const override;

		bool IntersectsLocal(const Ray3D& ray) const override;

		BoundingBox3D BoundingBoxLocal() const override;

		Vector3D ClosestNormalLocal(const Vector3D& otherPoint) const override;

		SurfaceRayIntersection3 ClosestIntersectionLocal(const Ray3D& ray) const override;
	};

	//! Shared pointer type for the Box3.
	using Box3Ptr = std::shared_ptr<Box3>;
	
	//!
	//! \brief Front-end to create Box3 objects step by step.
	//!
	class Box3::Builder final : public SurfaceBuilderBase3<Box3::Builder>
	{
	public:
		//! Returns builder with lower corner set.
		Builder& WithLowerCorner(const Vector3D& pt);

		//! Returns builder with upper corner set.
		Builder& WithUpperCorner(const Vector3D& pt);

		//! Returns builder with bounding box.
		Builder& WithBoundingBox(const BoundingBox3D& bbox);

		//! Builds Box3.
		Box3 Build() const;

		//! Builds shared pointer of Box3 instance.
		Box3Ptr MakeShared() const;

	private:
		Vector3D m_lowerCorner{ 0, 0, 0 };
		Vector3D m_upperCorner{ 1, 1, 1 };
	};
}

#endif