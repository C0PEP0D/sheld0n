
template<typename tSpaceVector, template<typename...> typename tView>
class Flow {
    public:
        static tSpaceVector getVelocity(const double* pX, const double t) {
            return tView<const tSpaceVector>(pX); // Exponential derivative
        }
};

