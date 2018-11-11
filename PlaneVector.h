#pragma once
namespace Mya {

	/*平面ベクトル管理運用コンテナ
	名前空間：Mya*/

	class PlaneVector
	{
	private:
		double X;
		double Y;
		double SquaringSize;//大きさの二乗
		long double Size;
		long double XperUnitSize;
		long double YperUnitSize;
		long double UnitMultiple;//大きさを１にするためには自身を何倍にすればよいかを格納
		Mya::PlaneVector* SubtractionLeft = nullptr;
		Mya::PlaneVector* SubtractionRight = nullptr;
		void updateProperty();//プロパティを更新
	public:
		/*自身のベクトルの要素と基本プロパティ*/

		//ベクトルの成分を指定(x,y)
		void setComponent(double, double);
		//ベクトルのx成分を指定
		void setX(double);
		//ベクトルのy成分を指定
		void setY(double);
		//ベクトルの大きさを返す
		double size();
		//x成分を返す
		double x() { return X; };
		//y成分を返す
		double y() { return Y; };
		/*ゼロベクトル*/

		//ゼロベクトルにする
		void setZero();
		//ゼロベクトルかどうかを返す
		bool isZero() { return Size == 0; };
		/*大きさを操作する*/

		//指定の大きさの時のx成分を返す
		double scalarMultipleX(double);
		//指定の大きさの時のy成分を返す
		double scalarMultipleY(double);
		//指定の大きさの時の自身のベクトルを返す
		Mya::PlaneVector* getScalarMultipleVector(double);
		/*向きを操作する*/
		//自身の逆ベクトルを返す
		Mya::PlaneVector* getInverse();
		//自身を逆転させる
		void invert();
		/*ベクトルの演算*/

		//他のベクトルとの加算時のx成分を返す
		double x(Mya::PlaneVector*);
		//他のベクトルとの加算時のy成分を返す
		double y(Mya::PlaneVector*);
		//左辺ベクトル - 右辺ベクトル を自身に適用
		void setSubtraction(Mya::PlaneVector*, Mya::PlaneVector*);
		//setSubtractionにて登録した 左辺ベクトル - 右辺ベクトル を更新し、自身に適用　エラー時はfalseを返す
		bool updateSubtraction();
		/*ユーティリティ*/
		//コンストラクタ
		PlaneVector() {};
		//ベクトルの成分を指定してコンストラクタ(x,y)
		PlaneVector(double, double);
	};
}